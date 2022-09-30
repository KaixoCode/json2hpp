
#include <array>
#include <tuple>
#include <string_view>

#include "generated/data.hpp"

int main() {
    constexpr auto item0 = data.menu.popup.menuitem[0];
    constexpr auto id = data.menu.id;
    constexpr auto onclick = data.menu.popup.menuitem[2].onclick;
}