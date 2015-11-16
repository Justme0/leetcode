class ListNode
	attr_accessor :val, :next

	def initialize(val)
		@val = val
		@next = nil
	end

	def del_self
		@val = @next.val
		@next = @next.next
	end
end

def delete_node(node)
	node.del_self
end
