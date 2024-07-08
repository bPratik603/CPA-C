class node: 
    def __init__(self, new_data=0): 
        self.data = new_data 
        self.prev = None 
        self.next = None 

class linked_list_iterator: 
    def __init__(self, G): 
        self.G = G 

    def __next__(self): 
        return self.G.__next__()

class linked_list: 
    def __init__(self): 
        self.head_node = node(-1)
        self.head_node.prev = self.head_node 
        self.head_node.next = self.head_node 

    @staticmethod 
    def g_insert(n_beg, n_mid, n_end): 
        n_mid.next = n_end 
        n_mid.prev = n_beg 
        n_beg.next = n_mid 
        n_end.prev = n_mid 

    def insert_end(self, new_data): 
        linked_list.g_insert(self.head_node.prev, node(new_data), self.head_node)

    def __iter__(self): 
        def get_generator(head_node): 
            p_run = head_node.next 
            while p_run != head_node: 
                yield p_run.data 
                p_run = p_run.next 
        return linked_list_iterator(get_generator(self.head_node))

    def __str__(self): 
        lst_str = "[START]<->"
        p_run = self.head_node.next 
        while p_run != self.head_node: 
            lst_str += "[{}]<->".format(str(p_run.data))
            p_run = p_run.next 
        lst_str += "[END]"
        return lst_str 

def main(): 
    LL = linked_list() 
    for i in range(10): 
        LL.insert_end((i+1) * 10)
    print(LL)

    for x in LL:
        print(x)

main()
