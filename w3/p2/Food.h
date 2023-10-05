#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H
namespace sdds {
	class Food {
		//PRIVATE:
		char f_name[31];//up to 30 characters
		int f_cal;//valid between 0 and 3000 calories (including 3000)
		int f_time;//1,2,3,4

	public:
		void setEmpty();
		bool isValid() const;//***
		int calories() const;
		void set(const char* newName, int newCal, int newTime);
		void display()const;

	};
}
#endif // !1
