#pragma once

#include "Engine/Quests/QuestTask.h"

class HelpTotem;
class MagePortal;
class Marcel;
class QuestLine;
class Squally;

class TeachHackerMode : public QuestTask
{
public:
	static TeachHackerMode* create(GameObject* owner, QuestLine* questLine, std::string questTag);

	static const std::string MapKeyQuest;

protected:
	TeachHackerMode(GameObject* owner, QuestLine* questLine, std::string questTag);
	~TeachHackerMode();

	void onLoad(QuestState questState) override;
	void onActivate(bool isActiveThroughSkippable) override;
	void onComplete() override;
	void onSkipped() override;

private:
	typedef QuestTask super;

	void runCinematicSequencePt1();
	void runCinematicSequencePt2();

	bool hasRunEvent;
	HelpTotem* helpTotem;
	MagePortal* portal;
	Marcel* marcel;
	Squally* squally;

	static const std::string TagQuestPortal;
	static const std::string TagHelpTotemHacking;
};
