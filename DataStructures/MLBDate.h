//
// Created by aj on 5/24/16.
//

#ifndef BASEBALL_PI_MLBDATE_H
#define BASEBALL_PI_MLBDATE_H


#include <ctime>
#include <glibmm/ustring.h>

class MLBDate {
private:
    const size_t MAX_FORMAT_LENG = 28;
    Glib::ustring * formatStr;
    void formatString();
public:
    int day;
    int month;
    int year;

    MLBDate();
    MLBDate(time_t date);
    MLBDate(Glib::ustring mm, Glib::ustring dd, Glib::ustring yy);
    MLBDate(int mm, int dd, int yy);
    Glib::ustring MLBDateString();
};


#endif //BASEBALL_PI_MLBDATE_H
