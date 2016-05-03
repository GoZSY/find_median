/*******************************************************************
利用大小堆原理实现数据流中的中位数的实时提取，使用了STL中的优先级队列
的特性
********************************************************************/
class Solution {
public:
    void Insert(int num)
    {
        count++;
        if(count%2==0)
        {
            big_heap.push(num);
            int value = big_heap.top();
            small_heap.push(value);
            big_heap.pop();
        }
        else
        {
            small_heap.push(num);
            int value = small_heap.top();
            big_heap.push(value);
            small_heap.pop();
        }
    }

    double GetMedian()
    { 
        if(count%2==0)
        {
            return double((big_heap.top() + small_heap.top()))/2;
        }
        else
            return big_heap.top();
    
    }
private:
    int count = 0;
    priority_queue<int, vector<int>, less<int> > big_heap;
    priority_queue<int, vector<int>, greater<int> > small_heap;
};
