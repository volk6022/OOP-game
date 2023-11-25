//#include <iostream>
//#include <fstream>
//#include <algorithm>
//#include <string>
//
//
//int* matrix_search(int** matr, int n, int m, int a, int* c) {
//	if (matr[c[0]][c[1]] == a)
//		return c;
//	if (c[0] == n || c[1] == m)
//		return NULL;
//	if (c[1] < m && matr[c[0]+1][c[1]] <= a) {
//		c[0] += 1;
//		std::cout << c[0] << ' ' << c[1] << ' ' << matr[c[0]][c[1]] << '\n';
//		return matrix_search(matr, n, m, a, c);
//	}
//	if (c[0] < n && matr[c[0]][c[1]+1] <= a) {
//		c[1] += 1;
//		std::cout << c[0] << ' ' << c[1] << ' ' << matr[c[0]][c[1]] << '\n';
//		return matrix_search(matr, n, m, a, c);
//	}
//}
//
//
//void FiveLines() {
//	std::ifstream in ("path in");
//	
//}

/*
int main() {
	const int n = 5, m = 5, a = 1;
	int** b = new int*[m];
	b[0] = new int[n] { 1, 2, 3, 4, 5 };
	b[1] = new int[n] { 11, 12, 13, 14, 15 };
	b[2] = new int[n] { 21, 22, 23, 24, 25 };
	b[3] = new int[n] { 31, 32, 33, 34, 35 };
	b[4] = new int[n] { 42, 46, 50, 60, 61 };

	int* c = new int[2];
	c[0] = 0, c[1] = 0;
	c = matrix_search(b, n, m, a, c);

	if (c == NULL)
		std::cout << "NO\n";
	else
		std::cout << c[0] << ' ' << c[1] << '\n';
	// доделать крайние случаи


	std::ifstream in("C:\\Users\\bhunp\\OneDrive\\Documents\\tets_text.txt");
	std::string s;
	std::getline(in, s);
	std::cout << s << '\n';

	return 0;
}
*/