class ListNode
	attr_accessor :val, :next

	def initialize(val)
		@val = val
		@next = nil
	end

	def delete_at(index)
		fail unless index >= 1
		p = self
		(index - 1).times do
			p = p.next
		end
		p.next = p.next.next
	end

	def size
		size = 1
		p = @next
		while !p.nil?
			p = p.next
			size += 1
		end
		size
	end
end

def remove_nth_from_end(head, n)
	size = head.size
	num = size - n
	return head.next if num == 0
	head.delete_at(num)
	head
end
