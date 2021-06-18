#include <iostream>

using namespace std;

class IMood
{
public:
    virtual int checkYourMood() = 0;
};

class Mood : public IMood
{
public:
    virtual int checkYourMood()
    {
        return 0;
    }
};

class MoodDecorator : public IMood
{
public:
    IMood *finalMood;
    MoodDecorator(IMood *mood) : finalMood(mood) {}
    int checkYourMood()
    {
        finalMood->checkYourMood();
    }
};

class LecturerForbidYourLaboratoryTeacherToGiveYouActivityPoints : public MoodDecorator
{
public:
    LecturerForbidYourLaboratoryTeacherToGiveYouActivityPoints(IMood *mood) : MoodDecorator(mood) {}
    virtual int checkYourMood()
    {
        return MoodDecorator::checkYourMood() - 30;
    }
};

class LecturerLowersThePointsYouGotFromEssay : public MoodDecorator
{
public:
    LecturerLowersThePointsYouGotFromEssay(IMood *mood) : MoodDecorator(mood) {}
    virtual int checkYourMood()
    {
        return MoodDecorator::checkYourMood() - 50;
    }
};

class YourLaboratoryTeacherMakesARevolutionAndTakesThePlaceOfYourLecturerAndNowWholeUniversityUniverseIsHappy : public MoodDecorator
{
public:
    YourLaboratoryTeacherMakesARevolutionAndTakesThePlaceOfYourLecturerAndNowWholeUniversityUniverseIsHappy(IMood *mood) : MoodDecorator(mood) {}
    virtual int checkYourMood()
    {
        return MoodDecorator::checkYourMood() + 200;
    }
};

class YourBestLaboratoryTeacherMadeNewSong : public MoodDecorator
{
public:
    YourBestLaboratoryTeacherMadeNewSong(IMood *mood) : MoodDecorator(mood) {}
    virtual int checkYourMood()
    {
        return MoodDecorator::checkYourMood() + 50;
    }
};

class YouHaveTheBestLaboratoryTeacher : public MoodDecorator
{
public:
    YouHaveTheBestLaboratoryTeacher(IMood *mood) : MoodDecorator(mood) {}
    virtual int checkYourMood()
    {
        return MoodDecorator::checkYourMood() + 50;
    }
};

int main()
{
    IMood *mood = new LecturerLowersThePointsYouGotFromEssay(new LecturerForbidYourLaboratoryTeacherToGiveYouActivityPoints(new Mood()));
    cout << "Your mood is actually at level: " << mood->checkYourMood() << "\n";
    IMood *mood2 = new YourLaboratoryTeacherMakesARevolutionAndTakesThePlaceOfYourLecturerAndNowWholeUniversityUniverseIsHappy(new YouHaveTheBestLaboratoryTeacher(new Mood()));
    cout << "Your mood is actually at level: " << mood2->checkYourMood() << "\n";
    return 0;
}
