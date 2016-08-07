# include<iostream>
# include<vector>

using namespace std;

class sort_algorithm_interface
{
public:
    virtual void sort(std::vector<int> &input)  = 0;
};

class HeapSort : public sort_algorithm_interface
{
public:
    HeapSort(std::vector<int> &input);
    void Swap(std::vector<int> &input, std::vector<int>::size_type i, std::vector<int>::size_type j)
    {
        if(i == j)
            return;

        int temp;
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    void Sift(std::vector<int> &input, const std::vector<int>::size_type heapSize, const std::vector<int>::size_type siftNode)
    {
        std::vector<int>::size_type i, j;

        j = siftNode;
        do
        {
            i = j;
            if(((2*i + 1) < heapSize) && input[j] < input[2*i + 1])
                j = 2*i + 1;
            if(((2*i + 2) < heapSize) && input[j] < input[2*i + 2])
                j = 2*i + 2;

            Swap(input, i, j);
        }
        while(i != j);
    }

    void MakeInitialHeap(std::vector<int> &input)
    {
        for(int i = input.size() - 1; i >= 0; --i)
        {
            Sift(input, input.size(), i);
        }
    }

    virtual void sort(std::vector<int> &input)
    {
        MakeInitialHeap(input);
        for(std::vector<int>::size_type i = input.size()-1; i > 0; --i)
        {
            Swap(input, i, 0);
            Sift(input, i, 0);
        }
    }

};

class InsertionSort: public sort_algorithm_interface
{
public:
    virtual void sort(std::vector<int> &input)
    {

    }
};


int main()
{
    std::vector<int>::size_type size;
    std::vector<int> input;
    std::cout<<"How many numbers to be sorted?";
    std::cin>>size;

    std::cout<<"Enter the numbers to be sorted:-\n\n";

    int value;
    for(std::vector<int>::size_type i = 0; i < size; ++i)
    {
        std::cout<<"Enter number "<<i+1<<":";
        std::cin>>value;
        input.push_back(value);
    }

    sort_algorithm_interface &s = HeapSort(input);
    s.sort(input);


    for(std::vector<int>::size_type i = 0; i < input.size(); ++i)
    {
        std::cout<<input[i]<<"\t";
    }

    return 0;
}
