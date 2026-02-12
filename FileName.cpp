#include <iostream>
#include <vector>
#include <cstdint>

struct DATA {
	//hogehoge
};

struct Item {
	std::intmax_t No = 0;
	DATA D;
};

template<class C>
std::intmax_t Search(const C& Container, std::intmax_t N, auto Match) {

	auto Z = std::size(Container) > N ? N : std::size(Container);

	for (std::intmax_t i = 0; i < Z; i++) {
		if (Match(Container[i])) {
			return i;
		}
	}

	return -1;
}
/** /
template<class C, class T>
std::intmax_t Search(const C& Container, std::intmax_t N, const T& V) {

	auto Z = std::size(Container) > N ? N : std::size(Container);

	for (std::intmax_t i = 0; i < Z; i++) {
		if (Container[i]=V) {
			return i;
		}
	}

	return -1;
}
/**/

template<class Position=std::intmax_t>
Position for_search_n(auto beg, auto end, Position N, auto Lambada) {
	Position A = 0;
	for (auto it = beg; it != end; it++) {

		if (N == A) { return -1; }

		if (Lambada(A,it)) {
			return A;
		}

		A++;
	}
	return -1;
}



int main() {


	std::vector<char> V = { 1,2,3,4,5,6,7,-1 };

	auto N = Search(V, 4, [](auto& n) {return n == 5; });

	std::cout << N << std::endl;

	char X[] = {1,2,3,4,5,6,7,-1};

	auto N2 = for_search_n(X, X + 8, 4, [](auto,auto& n) {return *n == 5; });

	std::cout << N2 << std::endl;
	return 0;
}