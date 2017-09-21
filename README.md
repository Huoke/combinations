# combinations
generates combinations of symbols from string length n by k
Алгоритм
Комбинации генерируются в лексикографическом порядке. Алгоритм работает с порядковыми индексами элементов множества.
Рассмотрим алгоритм на примере.
Для простоты изложения рассмотрим множество из пяти элементов, индексы в котором начинаются с 1, а именно, 1 2 3 4 5.
Требуется сгенерировать все комбинации размера m = 3.
Сначала инициализуется первая комбинация заданного размера m — индексы в порядке возрастания
1 2 3
Далее проверяется последний элемент, т. е. i = 3. Если его значение меньше n - m + i, то он инкрементируется на 1.
1 2 4
Снова проверяется последний элемент, и опять он инкрементируется.
1 2 5
Теперь значение элемента равно максимально возможному: n - m + i = 5 - 3 + 3 = 5, проверяется предыдущий элемент с i = 2.
Если его значение меньше n - m + i, то он инкрементируется на 1, а для всех следующих за ним элементов значение приравнивается к значению предыдущего элемента плюс 1.
1 (2+1)3 (3+1)4 = 1 3 4
Далее снова идет проверка для i = 3.
1 3 5
Затем — проверка для i = 2.
1 4 5
Потом наступает очередь i = 1.
(1+1)2 (2+1)3 (3+1)4 = 2 3 4
И далее,
2 3 5
2 4 5
3 4 5 — последнее сочетание, так как все его элементы равны n - m + i.
taken from https://planetcalc.ru/3757/
