
#include "VTable.hpp"

template <typename... Funcs>
VTable<Funcs...>::VTable(Funcs... funcs) : data(std::make_tuple(std::forward<Funcs>(funcs)...))
{
}

template <typename... Funcs>
template <std::size_t Index, typename... Args>
decltype(auto) VTable<Funcs...>::invoke(Args &&...args) const
{
	return std::get<Index>(data)(std::forward<Args>(args)...);
}
