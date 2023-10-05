/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 9
// Version 1.0
// Description
// Collection template
//
// Revision History
// -----------------------------------------------------------
// Name   Siripa Purinruk      Date  31/7/2023         Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
namespace sdds {
    /*
    * Collection class template
    * typename => T can be any data type
    */
   template <typename T>
   class Collection {
      /*T can be data type*/
      T* m_data = nullptr;
      int m_size = 0;
   public:
      
      Collection(int size = 0);
      Collection(const Collection<T>& CP);
      Collection<T>& operator=(const Collection<T>& RO);
      int size()const;
      void resize(int newsize);
      T& operator[](int index);
      Collection<T>& add(const T& element);
      ~Collection();
   };

   
   /*Why need to specify "Collection<T>"???
   Since T is part of the class template, it needs to be explicitly 
   specified when accessing its members and member functions from outside 
   the class definition.
   */
   /*constructor: T can be any datatype in Collection class
   @param - size*/
   template <typename T>
   Collection<T>::Collection(int size) :m_size(size) {
      if (m_size <= 0) m_size = 0;
      if (m_size > 0) m_data = new T[m_size];
   }

   /*constructor: T can be any datatype in Collection class
   @param - CP which is the collection Obj.*/
   template <typename T>
   Collection<T>::Collection(const Collection<T>& CP) {
      operator=(CP);
   }

   /*assignment operator for
   obj T = obj T_RO*/
   template <typename T>
   Collection<T>& Collection<T>::operator=(const Collection<T>& RO) {
      if (this != &RO) {
         delete[] m_data;
         m_data = new T[m_size = RO.m_size];
         for (int i = 0; i < m_size; i++) m_data[i] = RO.m_data[i];
      }
      return *this;
   }

   /*getter 
   return - m_size of T obj*/
   template <typename T>
   int Collection<T>::size()const {
      return m_size;
   }

   /*allocation
   @param - newsize
   return - void*/
   template <typename T>
   void Collection<T>::resize(int newsize) {
      int i;
      T* temp = nullptr;
      if (newsize < 0) newsize = 0;
      if (newsize > 0) {
         temp = new T[newsize];
         for (i = 0; i < m_size && i < newsize; i++) {
            temp[i] = m_data[i];
         }
      }
      delete[] m_data;
      m_data = temp;
      m_size = newsize;
   }

   /* getter return m_data
   * @param - index
   * return - m_data[index] if index < m_size 
   */
   template <typename T>
   T& Collection<T>::operator[](int index) {
      if (index >= m_size) resize(index + 1);
      return m_data[index];
   }

   /*add new element to the Class
   * @param - element - is T m_data
   * return - Collection Obj.
   */
   template <typename T>
   Collection<T>& Collection<T>::add(const T& element) {
      (*this)[size()] = element;
      return *this;
   }

   /*Destructor
   */
   template <typename T>
   Collection<T>::~Collection() {
      delete[] m_data;
   }

  
}

#endif // !SDDS_COLLECTION_H_



