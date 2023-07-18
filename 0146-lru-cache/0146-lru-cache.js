function DLL(key,val,prev, next){
    this.key = key === undefined ? -1 : key;
    this.val = val === undefined ? -1 : val;
    this.prev = prev === undefined ? null : prev;
    this.next = next === undefined ? null : next;
}

var LRUCache = function(capacity) {
    this.head = new DLL();
    this.tail = new DLL();
    this.m = new Map();
    this.capacity = capacity;
    this.head.next = this.tail
    this.tail.prev = this.head
};

LRUCache.prototype.deleteNode = function(node) {
    let prev = node.prev
    let next = node.next
    
    prev.next = next
    next.prev = prev
};

LRUCache.prototype.addfront = function(node) {
    let prev = this.head
    let next = this.head.next
    node.prev = prev
    node.next = next
    prev.next = node
    next.prev = node
};

LRUCache.prototype.get = function(key) {
    if(this.m.get(key) === undefined) return -1;
    
    let node = this.m.get(key)
    this.deleteNode(node)
    this.addfront(node)
    // console.log(node)
    return node.val
};

LRUCache.prototype.put = function(key, value) {
    if(this.m.get(key) !== undefined){
        let node = this.m.get(key)
        node.val = value
        this.deleteNode(node)
        this.addfront(node)
        return
    }
    if(this.capacity === this.m.size){
        this.m.delete(this.tail.prev.key)
        this.deleteNode(this.tail.prev)
    }
    let node = new DLL(key,value)
    this.addfront(node)
    this.m.set(key,node)
};
