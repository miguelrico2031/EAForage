#pragma once
#include <chrono>
#include <string>
#include <vector>

class Task;
class Project;
class Skill;
class Workspace;

class CareerManager
{
public:
    void startCareer();
    void choosePath();
    void levelUp();
    int getProgress() const;

private:
    std::string careerName;
    int level;
    CareerPath* currentPath;
    int progress;
    Workspace* workspace;
};

class CareerPath
{
public:
    virtual void completeTask() = 0;
    virtual void earnBonus() = 0;
    virtual void promote() = 0;

protected:
    Task* currentTask;
    Project* currentProject;
    std::vector<Skill> skills;
};

class ProgrammerPath : public CareerPath
{
public:
    void debugCode();

private:
    int programmingSkillLevel;
    int logicSkillLevel;
};

class DesignerPath : public CareerPath
{
public:
    void createArtAsset();
    void pitchGameIdea();

private:
    int paintingSkillLevel;
    int writingSkillLevel;
    int mediaProductionSkillLevel;
};

class Skill
{
public:
    int getSkillLevel() const;
    void increaseSkillLevel();
    void addExperience(int xp);

private:
    std::string skillName;
    int skillLevel;
    int experiencePoints;
};

class Reward
{
public:
    int getRewardValue() const;
    bool getIsUnlocked() const;
    void unlockReward();
    void applyReward();

private:
    std::string rewardType;
    int rewardValue;
    bool isUnlocked;
};

class Task
{
public:
    void assignTask();
    void complete();
    std::vector<Reward> giveRewards() const;

private:
    std::string taskName;
    std::string skillRequired;
    int timeToComplete;
    bool isCompleted;
    std::vector<Reward> rewards;
};

class Project
{
public:
    void startProject();
    void submitProject();
    float calculateSuccess();
    std::vector<Reward> giveRewards() const;

private:
    std::string projectName;
    int difficulty;
    float successRate;
    std::chrono::time_point<std::chrono::system_clock> deadline;
    bool isSuccessful;
    std::vector<Reward> rewards;
};

class Workspace
{
public:
    virtual void work() = 0;
    virtual void interact() = 0;
};

class Office : public Workspace
{
public:
    void work() override;
    void interact() override;
    void attendWork();
    void interactWithColleagues();
    void useEquipment();

private:
    std::string location;
    std::vector<std::string> officeEquipment;
    std::vector<std::string> colleagues;
};

class HomeWorkspace : public Workspace
{
public:
    void work() override;
    void interact() override;
    void workFromHome();
    void upgradeSetup();
    void takeBreak();

private:
    std::string deskSetup;
    std::string PCQuality;
    int comfortLevel;
};
