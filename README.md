# Система управления движением на перекрестке
Этот код представляет собой реализацию системы управления движением на перекрестке двух дорог на языке программирования C++.

![roads](light.png)

## Условие задачи
На каждой дороге перед перекрестком установлен светофор. Светофор может быть либо зеленым, либо красным.

Зеленый свет означает, что автомобили могут проезжать перекресток в обоих направлениях по данной дороге.
Красный свет означает, что автомобили в обоих направлениях не могут проезжать перекресток и должны ждать, пока свет станет зеленым.
Светофоры на двух дорогах не могут быть одновременно зелеными. Это означает, что когда светофор зеленый на дороге A, он красный на дороге B, и наоборот.

Изначально светофор зеленый на дороге A и красный на дороге B. Когда светофор зеленый на одной дороге, все автомобили могут проезжать перекресток в обоих направлениях до тех пор, пока светофор не станет зеленым на другой дороге. Два автомобиля, движущиеся по разным дорогам, не должны проезжать перекресток одновременно.


# Решение:
Для обеспечения безопасности движения и избежания дедлоков на перекрестке используется следующий подход:

1) Для каждой дороги A и B устанавливается флаг, указывающий, на каком светофоре в данный момент включен зеленый свет.
2) Когда машина прибывает к перекрестку, она проверяет состояние светофора на своей дороге.
3) Если светофор еще не включен на дороге, который обслуживает автомобиль, то происходит включение светофора на этой дороге.
4) Автомобиль может пересечь перекресток, если светофор на его дороге зеленый.

# Функции: 
`void turnGreen(int* position)`: Эта функция переключает светофор на перекрестке. Принимает указатель на переменную position, которая указывает текущий статус светофора на дороге: 1 - зеленый на дороге A, 2 - зеленый на дороге B.

`void carArrived(int carId, int roadId, int direction, int* position)`: Эта функция вызывается, когда прибывает новый автомобиль к перекрестку. Принимает следующие параметры:

`carId` - идентификатор автомобиля;

`roadId` - идентификатор дороги, на которой прибывает автомобиль (1 для дороги A, 2 для дороги B);

`direction` - направление движения автомобиля;

`position` - указатель на переменную, хранящую текущий статус светофора.


# Примечания
1) Для предотвращения дедлоков и обеспечения безопасности движения автомобилей используется мьютекс m.
2) Каждый автомобиль ждет, пока светофор на его дороге не станет зеленым, прежде чем проехать перекресток.
3) В случае возникновения ситуации, когда светофор уже зеленый на дороге, которой подъезжает следующий автомобиль, выводится сообщение о включении зеленого света на другой дороге.
