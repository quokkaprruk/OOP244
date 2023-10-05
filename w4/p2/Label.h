#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H 
#include <iostream>
namespace sdds {

	class Label {
		
		//private:variables
		char* l_frame;//char l_frame[8+1];
		char* l_label;//char l_label[70 + 1];

	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void setDefaultLabel(); //add
		void setLabelContent(const char* content); //add
		void setLabelFrame(const char* frameArg); 
		void readLabel();
		bool checkValid();
		std::ostream& printLabel()const;
		void clearInputBuffer();//add
	};
}
#endif // !1
