// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LFUCache cache = new LFUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

package main

import (
	"container/list"
	"fmt"
)

type LFUCache struct {
	capacity int
	l        list.List             // value list
	elemPos  map[int]*list.Element // key to list position
}

type KV struct {
	key   int
	value int
	cnt   int // visit count of key
}

func Constructor(capacity int) LFUCache {
	cache := LFUCache{}
	cache.capacity = capacity
	cache.elemPos = make(map[int]*list.Element)

	return cache
}

func (this *LFUCache) Get(key int) int {
	fmt.Print("after Get ", key, ", ")
	e := this.elemPos[key]
	if nil == e {
		// printlist(this.l) // if print, LTE; best solution is use map to record first and last equal elements
		return -1
	}

	// already exists
	value := e.Value.(KV).value
	e.Value = KV{key, value, e.Value.(KV).cnt + 1} // update cnt
	this.PreviousMove(e)

	// printlist(this.l)
	return value
}

// move to first sorted position; the list is big to small order.
func (this *LFUCache) PreviousMove(e *list.Element) {
	it := e.Prev()
	for ; it != nil; it = it.Prev() {
		if it.Value.(KV).cnt > e.Value.(KV).cnt {
			break
		}
	}
	if it != nil {
		this.l.MoveAfter(e, it)
	} else {
		this.l.MoveToFront(e)
	}
}

func (this *LFUCache) Put(key int, value int) {
	fmt.Print("after Put ", key, " ", value, ", ")
	if this.capacity == 0 {
		// printlist(this.l)
		return
	}

	e := this.elemPos[key]
	if nil != e {
		// already exists
		e.Value = KV{key, value, e.Value.(KV).cnt + 1} // update to new value & cnt
		this.PreviousMove(e)
		// printlist(this.l)
		return
	}

	// no exists
	if this.l.Len() >= this.capacity {
		back := this.l.Back()
		this.l.Remove(back)
		delete(this.elemPos, back.Value.(KV).key)
	}
	e = this.l.PushBack(KV{key, value, 0})
	this.PreviousMove(e)
	this.elemPos[key] = e
	// printlist(this.l)
}

/**
* Your LFUCache object will be instantiated and called as such:
 */

func printlist(l list.List) {
	// Iterate through list and print its contents.
	fmt.Print("list is ")
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Print(e.Value, " ")
	}
	fmt.Println()
}

func test(op []string, value [][]int) {
	cache := Constructor(value[0][0])
	for i := 1; i < len(op); i++ {
		if op[i] == "put" {
			cache.Put(value[i][0], value[i][1])
		} else {
			fmt.Println("=====", cache.Get(value[i][0]))
		}
	}
}

func main() {
	op := []string{"LFUCache", "put", "put", "put", "put", "put", "get", "put", "get", "get", "put", "get", "put", "put", "put", "get", "put", "get", "get", "get", "get", "put", "put", "get", "get", "get", "put", "put", "get", "put", "get", "put", "get", "get", "get", "put", "put", "put", "get", "put", "get", "get", "put", "put", "get", "put", "put", "put", "put", "get", "put", "put", "get", "put", "put", "get", "put", "put", "put", "put", "put", "get", "put", "put", "get", "put", "get", "get", "get", "put", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "get", "get", "get", "put", "put", "put", "get", "put", "put", "put", "get", "put", "put", "put", "get", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "put", "put", "put"}
	value := [][]int{{10}, {10, 13}, {3, 17}, {6, 11}, {10, 5}, {9, 10}, {13}, {2, 19}, {2}, {3}, {5, 25}, {8}, {9, 22}, {5, 5}, {1, 30}, {11}, {9, 12}, {7}, {5}, {8}, {9}, {4, 30}, {9, 3}, {9}, {10}, {10}, {6, 14}, {3, 1}, {3}, {10, 11}, {8}, {2, 14}, {1}, {5}, {4}, {11, 4}, {12, 24}, {5, 18}, {13}, {7, 23}, {8}, {12}, {3, 27}, {2, 12}, {5}, {2, 9}, {13, 4}, {8, 18}, {1, 7}, {6}, {9, 29}, {8, 21}, {5}, {6, 30}, {1, 12}, {10}, {4, 15}, {7, 22}, {11, 26}, {8, 17}, {9, 29}, {5}, {3, 4}, {11, 30}, {12}, {4, 29}, {3}, {9}, {6}, {3, 4}, {1}, {10}, {3, 29}, {10, 28}, {1, 20}, {11, 13}, {3}, {3, 12}, {3, 8}, {10, 9}, {3, 26}, {8}, {7}, {5}, {13, 17}, {2, 27}, {11, 15}, {12}, {9, 19}, {2, 15}, {3, 16}, {1}, {12, 17}, {9, 1}, {6, 19}, {4}, {5}, {5}, {8, 1}, {11, 7}, {5, 2}, {9, 28}, {1}, {2, 2}, {7, 4}, {4, 22}, {7, 24}, {9, 26}, {13, 28}, {11, 26}}
	test(op, value)
}
