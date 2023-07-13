#include <iostream>
#include <vector>
using namespace std;

//COSTE: O(v.size()[inicial])
/*
* todas las instrucciones son de coste constante, pero
* se repiten las del bucle tantas veces como elementos
* tenga el vector v
*/

/*P:
	Definimos
*	m ::= v.size() al inicio de la llamada de la fun
*	V[] = v[]
*/
void resover(vector<int>& v) {
	int cont = 0;

	/*FUNCION DE COTA
	*	v.size() - i
	*/
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] % 2 == 0) {
			v[cont] = v[i];
			++cont;
		}
	}
	/* INVARIANTE
	*	0 <= i <= v.size()
	* ^	0 <= cont <= i
	* ^ PARA_TODO j : 0 <= j <= i : PARA_TODO e : 0 <= e < cont : v[e] % 2 == 0
	*/

	v.resize(cont);
}
/* Q:
* 
*	0 <= v.size() <= V.size()
* ^
*	PARA_TODO i : 0 <= i < v.size() : v[i] % 2 == 0
* ^
*	PARA_TODO w : 0 <= w < V.size() : (EXISTE e : 0 <= e < v.size(): v[w] == v[e];
*/

int main() {
	int c;
	cin >> c;

	while (c > 0)
	{
		int n;
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];		

		resover(v);

		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";

		cout << endl;
		--c;
	}

	return 0;
}