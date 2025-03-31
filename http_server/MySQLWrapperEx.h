#include "SafeResultSet.h"

class MySQLWrapperEx : public MySQLWrapper {
public:
    using QueryRow = SafeResultSet::Row;
   
};