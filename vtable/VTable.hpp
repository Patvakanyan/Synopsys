#pragma once

#include <tuple>
#include <utility>

template <typename... Funcs>
class VTable
{
private:
	std::tuple<Funcs...> data;

public:
	explicit VTable(Funcs... funcs);
	VTable() = default;
	VTable(const VTable &other) = default;
	VTable(VTable &&other) noexcept = default;

	VTable &operator=(const VTable &other) = default;
	VTable &operator=(VTable &&other) noexcept = default;

	template <std::size_t Index, typename... Args>
	decltype(auto) invoke(Args &&...args) const;
	~VTable() = default;
};

#include "VTable.tpp"
