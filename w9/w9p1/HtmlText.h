#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
     // int getFileLength()const;

   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);

      //rule of three
      HtmlText (const HtmlText& src);
      HtmlText& operator= (const HtmlText& src);
      ~HtmlText();

      void write(std::ostream& os)const override;

      void setEmptyState() override;
   };
}
#endif // !SDDS_HTMLTEXT_H_
