#include <vector>

class fenwick_tree
{
private:
    int _limit;
    std::vector<long long> _tree;

public:
    fenwick_tree(int limit)
    {
        _limit = limit;

        std::vector<long long> tree(_limit);
        _tree = tree;
    }

    void add(long long index, long long value) {
        if(index <= 0) return;
        while(index <= _limit) {
            _tree[index] += value;
            index += index & -index;
        }
    }

    long long read(int index) {
        long long sum = 0;
        while(index > 0) {
            sum += _tree[index];
            index -= index & -index;
        }
        return sum;
    }

    void replace(int index, long long value) {
        long long addingValue = value - elementAt(index);
        add(index, addingValue);
    }

    long long elementAt(int index) {
        return read(index) - read(index - 1);
    }
};