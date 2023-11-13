#include "include.h"
#include <chrono>
const int N = 100000;

int main()
{
	std::setlocale(LC_CTYPE, "rus");
	std::fstream g;
	auto begin = std::chrono::steady_clock::now();
	auto end = begin;
	auto time = end - begin;
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
	auto elapsed_s = std::chrono::duration_cast<std::chrono::seconds>(time);
	g.open("out.txt", std::ios::out);
	if (g.is_open()) {
		std::cout << " Автор: Гожан Максим Витальевич группа:2302\n АиСД\n Лабораторная работа #3 - Самобалансирующиеся двоичные деревья\n\n";
		g << "Автор: Гожан Максим Витальевич группа:2302\nАиСД\nЛабораторная работа #3 - Самобалансирующиеся двоичные деревья\n\n";
		int var = 0;
		Node* Root = NULL;
		Node* Elem = NULL;
		while (var < 1 || var >5) { // выбор дерева
			std::cout << "\nВыберете дерево:\n1 - Стандартное бинарное дерево поиска\n2 - Красно-черное дерево\n3 - АВЛ дерево\n4 - Создать перестановку\n5 - Выход из программы\n\n";
			std::cin >> var;
		}
		if (var == 4 || var == 5) {
			if (var == 5) {
				std::cout << "Завершение программы\n\n";
			}
			else {
				int A[N];
				int j;
				std::fstream f, q;
				f.open("in100000sorted.txt", std::ios::in);
				for (int i = 0; i < N; i++) {
					f >> A[i];
				}
				for (int i = 0; i < N; i++) {
					j = rand() % (i + 1);
					A[i] = A[j];
					A[j] = i + 1;
				}
				q.open("in100000random.txt", std::ios::out);
				for (int i = 0; i < N; i++) {
					q << A[i] << "\n";
				}
				q.close();
			}
		}
		else{
			if (N != 0) {
				if (Read(&Root, N, var)) {
					std::cout << "Read выполнено, дерево создано\n";
					int ask = 0;
					while (ask < 1 || ask >6) { // выбор функции
						std::cout << "\nВыберете функцию:\n1 - Обход дерева\n2 - Вставка элемента\n3 - Удаление элемента\n4 - Поиск\n5 - Вывод высоты дерева\n6 - Выход из программы\n\n";
						std::cin >> ask;

						if (ask == 1) { // обход дерева						
							do {
								std::cout << "\nВыберете режим обхода:\n1 - В ширину\n2 - Прямой (preorder)\n3 - Обратный (postorder)\n4 - Симмертричный (inorder)\n\n";
								std::cin >> ask;
							} while (ask < 1 || ask >4);

							if (ask == 1) {
								g << "\nОбход в ширину\n\n";
								std::cout << "\nОбход в ширину\n\n";
								LevelOrder(&Root, g);
							}							


							else if (ask == 2) { // прямой (preorder)
								g << "\nПрямой обход\n\n";
								std::cout << "\nПрямой обход\n\n";
								PreOrder(&Root, g);
							}


							else if (ask == 3) { // обратный (postorder)
								g << "\nОбратный обход\n\n";
								std::cout << "\nОбратный обход\n\n";
								PostOrder(&Root, g);
							}

							else { // симметричный (inorder)
								g << "\nСимметричный обход\n\n";
								std::cout << "\nСимметричный обход\n\n";
								InOrder(&Root, g);
								
							}
							ask = 0;
						}

						else if (ask == 2) { // вставка
							std::cout << "Введите ключ вставляемого элемента\n";
							auto mid = time;							//
							for (int i = 0; i < 1000; i++) {  					//
								if (i % 2 == 0) {
									ask = -80*i;
								}
								else {
									ask = N+25*i;
								}
								
							
							//std::cin >> ask;
							Node* n = new Node(ask);
							n = Insert(&Root, &n);
							Elem = n;
							if (var == 2) {
								Root = ToRoot(&Elem);
								Elem = n;
								begin = std::chrono::steady_clock::now();
								RBfixIns(&n, &Root);
								end = std::chrono::steady_clock::now();
								time = end - begin;
								elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
						
								std::cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
							}
							else if (var == 3) {
								Root = ToRoot(&Elem);
								Elem = n;
								begin = std::chrono::steady_clock::now();
								AVLfixIns(&n, &Root);
								end = std::chrono::steady_clock::now();
								time = end - begin;
								elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
						
								std::cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
							}
							Root = ToRoot(&Elem);
							mid += time;                                                              //
							}					                                                                    //
							auto el = std::chrono::duration_cast<std::chrono::nanoseconds>(mid/1000);					//
							std::cout << "\n\n" << el.count() << "\n\n";					//
							ask = 0;
						}

						else if (ask == 3) { // удаление
							std::cout << "Введите ключ удаляемого элемента\n";

							//auto mid = time;          					//
							for (int i = 0; i < 100; i++) { 		//
								if (i % 2 == 0) {		//
									ask = 40*i;		//
								}		//
								else {		//
									ask = N - 43*i;  //
								}					//
											

								//std::cin >> ask;
								Node* tmp = Search(&Root, ask);
								if (tmp != NULL) {
									//begin = std::chrono::steady_clock::now();          //
									Delete(&tmp, &Root, var);
									//end = std::chrono::steady_clock::now();        //
									//time = end - begin;                                 //
									//elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);        //

									//std::cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";      //
									//mid += time;                                                                  //
								}
								else {
									std::cout << "\nЭлемента с таким ключом нет в дереве\n\n";
								}
							}                                                                              //
							//auto el = std::chrono::duration_cast<std::chrono::nanoseconds>(mid /1000);		//
							//std::cout << "\n\n" << el.count() << "\n\n";				                     	//
							ask = 0;
						}

						else if (ask == 4) { // поиск
						
							do {
								std::cout << "\nВыберете цель поиска:\n1 - Элемент с заданым ключом\n2 - Минимальный\n3 - Максимальный\n4 - Последующий элемент (Successor)\n5 - Предшествующий (Predecessor)\n\n";
								std::cin >> ask;
							} while (ask < 1 || ask >5);

							if (ask == 1) { // по выбору
								std::cout << "\nВведите ключ поиска\n";
								std::cin >> ask;
								Node* tmp = Search(&Root, ask);
								if (tmp != NULL) {
									std::cout << "\nЭлемент " << tmp->key << " был найден, его адрес = " << tmp << "\n\n";
								}
								else {
									std::cout << "\nЭлемента с таким ключом нет в дереве\n\n";
								}
								ask = 0;
							}

							else if (ask == 2) { // минимальный
								Node* tmp = Root;
								tmp = SearchMin(&tmp);
								std::cout << "\nНаименьший элемент = " << tmp->key << " был найден, его адрес = " << tmp << "\n\n";
								ask = 0;
							}

							else if (ask == 3) { // максимальный
								Node* tmp = Root;
								tmp = SearchMax(&tmp);
								std::cout << "\nНаибольший элемент = " << tmp->key << " был найден, его адрес = " << tmp << "\n\n";
								ask = 0;
							}

							else if (ask == 4) { // последующий
								std::cout << "\nВыберете для какого элемента будет производится поиск\n\n";
								std::cin >> ask;
								Node* tmp = Search(&Root, ask);
								if (tmp != NULL) {
									tmp = Successor(&tmp);
									if (tmp == NULL) {
										std::cout << "У выбранного элемента нет последующего, так как он наибольший в дереве\n\n";
									}
									else {
										std::cout << "Последующий элемент = " << tmp->key << ", его адрес = " << tmp << "\n\n";
									}
								}
								else {
									std::cout << "\nЭлемента с таким ключом нет в дереве\n\n";
								}
								ask = 0;
							}

							else { // предшествующий
								std::cout << "\nВыберете для какого элемента будет производится поиск\n\n";
								std::cin >> ask;
								Node* tmp = Search(&Root, ask);
								if (tmp != NULL) {
									tmp = Predecessor(&tmp);
									if (tmp == NULL) {
										std::cout << "У выбранного элемента нет предшествующего, так как он наименьший в дереве\n\n";
									}
									else {
										std::cout << "Предыдущий элемент = " << tmp->key << ", его адрес = " << tmp << "\n\n";
									}
								}
								else {
									std::cout << "\nЭлемента с таким ключом нет в дереве\n\n";
								}
								ask = 0;
							}
						
						}

						else if (ask == 5) { // высота
							std::cout << "\nВысота дерева = " << Hight(&Root) - 1 << "\n\n";
							ask = 0;
						}



						else if (ask == 6) { // выход из программы
							std::cout << "Завершение программы\n\n";
						}
					}
				}
				else {
					std::cout << "Файл не был открыт\n\n";
				}
			}
			else {
				std::cout << "Файл пуст\n\n";
			}
		}
		g.close();
	}

}

