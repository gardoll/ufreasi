/** 
 *  user-FRiendly Elemental dAta procesSIng (uFREASI)
 *  
 *  Copyright © 2012 Oualid Khelefi.
 *
 *  Authors : see AUTHORS.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PARSER_H
#define PARSER_H

#include "data.h"
#include <QtGui>
#include <QtCore>
#include <iostream>

using namespace std;

class Data;

class Parser{
public:
    virtual QPair<int,QString> parse(QFile *file,class Data *data,class Processing *process) = 0; ///< Parsing Function
    virtual int getId() = 0; ///< Returns a unique identification.
    virtual QString getPrintableName() = 0; ///< Returns the parser's name for humain.

    static const QString ID_BLK ;
    static const QString ID_STD ;
    static const QString ID_QC ;
};

/**
  * Parser for the input CSV data file, raw data comming from the HR Element ICP-MS
  */

class ParserInHRElementCSV: public Parser{
public:
    QPair<int,QString> parse(QFile *file,Data *data,class Processing *process); ///< Parsing Function

    inline int getId()
    {
      return 2 ;
    }

    inline QString getPrintableName()
    {
      return "HR Element" ;
    }
};

/**
  * Parser for the input CSV data file, raw data comming from the Agilent ICP-MS
  */

class ParserInAgilentCSV: public Parser{
public:
    QPair<int,QString> parse(QFile *file,Data *data,class Processing *process); ///< Parsing Function

    inline int getId()
    {
      return 3 ;
    }

    inline QString getPrintableName()
    {
      return "Agilent" ;
    }
};

/**
  * Parser for the output CSV data file, processed results data comming from the application and stored on a file
  */

class ParserOutCSV: public Parser{
public:
    QPair<int, QString> parse(QFile *file,Data *data,class Processing *process); ///< Parsing Function

    inline int getId()
    {
      return  1 ;
    }

    inline QString getPrintableName()
    {
      return "Standard unparser" ;
    }
};

/**
  * Parser for the input CSV concentrations file, it contains known concentrations of standards and quality controls
  */

class ParserInSTDQC: public Parser{
public:
    QPair<int, QString> parse(QFile *file,Data *data,class Processing *process); ///< Parsing Function

    inline int getId()
    {
      return  0 ;
    }

    inline QString getPrintableName()
    {
      return "Standard samples file parser" ;
    }
};

#endif // PARSER_H
