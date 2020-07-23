class LRUCache{
private:
	//LRU数据结构
	struct Node{
		int key;
		int value;
		Node(int k,int v):key(k),value(v){}
	};
public:
	LRUCache(int c):capacity(c) {}
	
	int get(int key){
		if (cacheMap.find(key) == cacheMap.end())
			return -1; //这里产生缺页中断，根据页表将页面调入内存，然后set(key, value)
		//将key移到第一个，并更新cacheMap 
		cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void put(int key, int value){
		if (cacheMap.find(key) == cacheMap.end())
		{
			//淘汰最后一个，然后将其加到第一个位置
			if (cacheList.size() == capacity)
			{
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(Node(key,value));
			cacheMap[key] = cacheList.begin();
		} 
		else
		{
			//更新节点的值，并将其加到第一个位置
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	int capacity;
	list<Node> cacheList;
	unordered_map<int, list<Node>::iterator> cacheMap;
};
