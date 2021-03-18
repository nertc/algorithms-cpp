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
        while(index <= _limit) {
            _tree[index] += value;
            index += index & -index;
        }
    }

    long long read(int index) {
        ++index;
        long long sum = 0;
        while(index) {
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
        if(index == 0) read(index);
        return read(index) - read(index - 1);
    }
};