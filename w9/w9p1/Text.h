#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_

namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;

      int getFileLength()const;

   protected:
      const char& operator[](int index)const; //derived class can access

   public:
      Text(const char* filename=nullptr);

      //rule of three
      ~Text();
      Text(const Text& src);
      Text& operator=(const Text& src);

      virtual void setEmptyState();
      void read();
      virtual void write(std::ostream& os)const;

      //getters
      const char* getContent() const; 
   };

   std::ostream& operator<<(std::ostream& os,const Text& text); //dont forget const
}
#endif // !SDDS_TEXT_H_

