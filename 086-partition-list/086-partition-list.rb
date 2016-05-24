class ListNode
	attr_accessor :val, :next
	def initialize(val)
		@val = val
		@next = nil
	end
end

# ListNode
def remove_next(node)
	fail unless node.next != nil
	removed = node.next
	node.next = node.next.next
	return removed
end

# void
def insert_next(pos, node)
	node.next = pos.next
	pos.next = node
end

# ListNode
def search_first_pre(h, x)
	while h.next != nil and h.next.val < x do
		h = h.next
	end
	h
end

# @param {ListNode} head
# @param {Integer} x
# @return {ListNode}
def partition(head, x)
	h = ListNode.new(0)
	h.next = head
	pos_pre = search_first_pre(h, x)
	return h.next if pos_pre.next == nil
	pre = pos_pre.next
	while pre != nil and pre.next != nil
		if (pre.next.val < x)
			removed = remove_next(pre)
			fail unless removed != nil
			insert_next(pos_pre, removed)
			pos_pre = pos_pre.next
			fail unless pos_pre != nil and pos_pre.next != nil and pos_pre.next.val >= x
		else
			pre = pre.next
		end
	end
	h.next
end

def make_list(array)
	h = ListNode.new(0) # with head node
	p = h
	array.each do |x|
		p.next = ListNode.new(x)
		p = p.next
	end
	h
end

h = make_list([3, 1, 2]) # h means head node
p h.next

p partition(h.next, 3)

