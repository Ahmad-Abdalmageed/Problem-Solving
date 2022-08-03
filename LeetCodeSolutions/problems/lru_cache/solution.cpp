class KeyValNode
{
public:
  int mValue;
  int mKey;

  KeyValNode *mNextNode;
  KeyValNode *mPrevNode;

  KeyValNode() : mValue(0), mKey(0), mNextNode(nullptr), mPrevNode(nullptr) {}
  KeyValNode(int iVal, int iKey) : mValue(iVal), mKey(iKey), mNextNode(nullptr), mPrevNode(nullptr) {}
};

class LRUCache
{
public:
  LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);

private:
  std::unordered_map<int, KeyValNode *> mKeyPtrMap;
  KeyValNode *mLeastUsedNode;
  KeyValNode *mMostUsedNode;
  int mCapacity;

  void push(KeyValNode *iNode);
  void pop(KeyValNode *iNode);
};


// LEETCODE: 146. LRU Cache
LRUCache::LRUCache(int capacity) : mCapacity(capacity)
{
  mLeastUsedNode = new KeyValNode();
  mMostUsedNode = new KeyValNode();

  mLeastUsedNode->mNextNode = mMostUsedNode;
  mMostUsedNode->mPrevNode = mLeastUsedNode;
}

int LRUCache::get(int key)
{
  // Get node if Exists in Map
  if (mKeyPtrMap.find(key) != mKeyPtrMap.end())
  {
    // Update the Most Recently Used Node
    pop(mKeyPtrMap[key]);  // Remove the Used Node
    push(mKeyPtrMap[key]); // Add used node to the Right
    return mKeyPtrMap[key]->mValue;
  }
  return -1;
}

void LRUCache::put(int key, int value)
{
  // If already existing key and value remove this node
  if (mKeyPtrMap.find(key) != mKeyPtrMap.end())
    pop(mKeyPtrMap[key]);

  mKeyPtrMap[key] = new KeyValNode(value, key);
  push(mKeyPtrMap[key]);

  // If exceeding capacity -- Remove the Least Used Key
  if (mKeyPtrMap.size() > mCapacity)
  {
    KeyValNode *lru = mLeastUsedNode->mNextNode;
    pop(lru);
    mKeyPtrMap.erase(lru->mKey);
  }
}

void LRUCache::push(KeyValNode *iNode)
{
  KeyValNode *prvMostUsed = mMostUsedNode->mPrevNode;
  KeyValNode *nxtMostUsed = mMostUsedNode;

  prvMostUsed->mNextNode = iNode;
  nxtMostUsed->mPrevNode = iNode;

  iNode->mPrevNode = prvMostUsed;
  iNode->mNextNode = nxtMostUsed;
}

void LRUCache::pop(KeyValNode *iNode)
{
  KeyValNode *prvMostUsed = iNode->mPrevNode;
  KeyValNode *nxtMostUsed = iNode->mNextNode;

  prvMostUsed->mNextNode = nxtMostUsed;
  nxtMostUsed->mPrevNode = prvMostUsed;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */