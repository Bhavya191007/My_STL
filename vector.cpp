#include<iostream>
#include<memory>
template<typename T>
class vector
{
	private:
        std::unique_ptr<T[]>data;
        std::size_t csize=0;
        std::size_t capacity=2;
    public:
        vector():data(std::make_unique<T[]>(2)),csize(0),capacity(2){}
        void push_back(T value)
        {
            if(csize==capacity)
            {
                resize(capacity*2);
            }
            data[csize]=value;
            csize++;
        }
        T& operator[](std::size_t index){
            return data[index];
        }
    private:
        void resize(std::size_t c)
        {
            auto new_data=std::make_unique<T[]>(c);
            for(int i=0;i<csize;i++)
            {
                new_data[i]=data[i];
            }
            data=std::move(new_data);
            capacity=c;
        }

};

int main()
{
    vector<std::string>vec;
    vec.push_back("Bhavya");
    vec.push_back("Samarth");
    std::cout<<vec[0]<<vec[1]<<"\n";
    return 0;
}