/* 
    On Windows OS 

    GlobalAlloc() 
    HeapAlloc() 
    VirtualAlloc() 

    On Linux OS 

    mmap() 

    At the time of start of any process: 

    Heap = Process Address Range - text - rodata - data - bss - stack 

    Rule: By default, all addresses in heap are INVALID. 
        Therefore, loading any address in heap, in pointer 
        and then de-referencing it would result into segmentation fault. 
        (Refer second comment)

        To avoid that and in order to use heap memory, first of all 
        the address in heap must be validated. And this task can be done 
        ONLY BY THE OS and not by the LANG. 
*/

/* 
    Revision Point: 
        Putting an invalid address in pointer is not an error. 
        But de-referencing a pointer containing an invalid address 
        for read / write or / execute (i.e. attempting to read from / 
        write to addr in pointer to trying to transfer control flow to 
        address in pointer) LEADS TO A MEMORY ACCESS VIOLATION WHICH 
        IN TURN TERMINATES THE PROCESS CAUSING IT. 

        IN SHORT 

        DEREFERENCE A POINTER CONTAINING INVALID ADDR = 
        TERMINATION OF PROCESS 
*/