#include "Utils.hpp"

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data *data = new Data(42);
	uintptr_t serialized_data = Serializer::serialize(data);
	Data *deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << std::endl;

	std::cout << Cyan << "Data : " << Yellow << data->getValue() << Reset_Color << std::endl;
	std::cout << Cyan << "Serialized Data : " << Yellow << serialized_data << Reset_Color << std::endl;
	std::cout << Cyan << "Deserialized Data : " << Yellow << deserialized_data->getValue() << Reset_Color << std::endl;

	std::cout << std::endl;

	std::cout << Cyan << "Address of data: " << Yellow << data << Reset_Color << std::endl;
	std::cout << Cyan << "Address of serialized_data: " << Yellow << &serialized_data << Reset_Color << std::endl;
	std::cout << Cyan << "Address of deserialized_data: " <<  Yellow <<deserialized_data << Reset_Color << std::endl;

	std::cout << std::endl;

	deserialized_data->setValue(21);
	std::cout << Cyan << "Deserialized Data : " << Yellow << deserialized_data->getValue() << Reset_Color << std::endl;
	std::cout << Cyan << "Data : " << Yellow << data->getValue() << Reset_Color << std::endl;

	std::cout << std::endl;

	return (0);
}