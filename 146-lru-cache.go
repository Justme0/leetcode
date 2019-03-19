// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

package main

import (
	"container/list"
	"fmt"
)

type LRUCache struct {
	capacity int
	l        list.List             // value list
	elemPos  map[int]*list.Element // key to list position
}

type KV struct {
	key   int
	value int
}

func Constructor(capacity int) LRUCache {
	cache := LRUCache{}
	cache.capacity = capacity
	cache.elemPos = make(map[int]*list.Element)

	return cache
}

func (this *LRUCache) Get(key int) int {
	e := this.elemPos[key]
	if nil == e {
		return -1
	}

	// fmt.Println("list is ", this.l)
	// fmt.Println("e is ", e.Value.(int))

	this.l.MoveToFront(e)

	return e.Value.(KV).value
}

func (this *LRUCache) Put(key int, value int) {
	e := this.elemPos[key]
	if nil != e {
		// already exists
		e.Value = KV{key, value} // update to new value
		this.l.MoveToFront(e)
		return
	}

	// no exists
	e = this.l.PushFront(KV{key, value})
	this.elemPos[key] = e

	if this.l.Len() > this.capacity {
		back := this.l.Back()
		this.l.Remove(back)
		delete(this.elemPos, back.Value.(KV).key)
	}
}

/**
* Your LRUCache object will be instantiated and called as such:
 */

func main() {
	capacity := 1
	cache := Constructor(capacity)

	cache.Put(2, 1)
	fmt.Println("value is ", cache.Get(2))
	// cache.Put(4, 4)
	// fmt.Println("value is ", cache.Get(1))
}
