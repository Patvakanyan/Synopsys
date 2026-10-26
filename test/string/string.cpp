
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::string a = "str";

	const unsigned char *bytes =
		reinterpret_cast<const unsigned char *>(&a);

	std::cout << "Object address: "
			  << static_cast<const void *>(&a) << '\n';

	std::cout << "Data address:   "
			  << static_cast<const void *>(a.data()) << '\n';

	std::cout << "Object size:    "
			  << sizeof(a) << " bytes\n\n";

	for (std::size_t i = 0; i < sizeof(a); ++i)
	{
		std::cout << "Offset +" << std::setw(2) << std::dec << i
				  << " | Address: "
				  << static_cast<const void *>(bytes + i)
				  << " | Hex: 0x"
				  << std::hex << std::setw(2)
				  << std::setfill('0')
				  << static_cast<unsigned int>(bytes[i])
				  << " | Dec: "
				  << std::dec
				  << static_cast<unsigned int>(bytes[i]);

		if (i >= 16 && i <= 19)
		{
			std::cout << " | ";
			if (bytes[i] >= 32 && bytes[i] <= 126)
				std::cout << "'" << static_cast<char>(bytes[i]) << "'";
			else
				std::cout << "(non-printable)";
		}

		std::cout << '\n';
	}
}
