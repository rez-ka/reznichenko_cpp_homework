0) иерархия файлов совпадает с предложенной в задании

1) с чем работаем:
транспорт: CheapBike, ElectricBike (множественное наследование)
вещи: Helmet

2) креативная часть: в Inventory.hpp добавлен оператор сравнения двух позиций по id

3) НАСЛЕДОВАНИЕ
InventoryItem > Transport; EnergyConsumer | > ElectricBike (множественное)
InventoryItem > Transport > CheapBike
InventoryItem > Helmet

4) ИСКЛЮЧЕНИЯ
класс CustomError
отдельно прописаны InspectionError (техосмотр не пройден) и ParsingError (в команде неправильные аргументы); 
они добавлены в реализацию некоторых методов в Transport.hpp

ИИ не использовался
