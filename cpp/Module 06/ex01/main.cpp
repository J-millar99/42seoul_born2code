#include "Serializer.hpp"

int main()
{
    Data *t_data = new Data(42);
    uintptr_t ptr;
    std::cout << t_data->num << std::endl;

    std::cout << "t_data: ";
    std::cout << t_data << std::endl;
    std::cout << "Data->uintptr_t->Data: ";
    ptr = Serializer::serialize(t_data);
    std::cout << Serializer::deserialize(ptr) << std::endl;
    delete t_data;
}