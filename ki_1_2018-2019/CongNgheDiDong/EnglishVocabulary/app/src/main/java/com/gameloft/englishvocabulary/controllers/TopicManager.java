package com.gameloft.englishvocabulary.controllers;

import com.gameloft.englishvocabulary.models.Topic;
import com.gameloft.englishvocabulary.models.Vocabulary;

import java.util.ArrayList;

public class TopicManager {

    private ArrayList<Topic> mTopicsList;
    private ArrayList<Vocabulary> mVocabularyList;

    private static TopicManager sInstance = null;

    private TopicManager(){
        mTopicsList = new ArrayList<>();
        mVocabularyList = new ArrayList<>();
    }

    public static TopicManager getInstance(){
        if(sInstance == null){
            sInstance = new TopicManager();
        }
        return sInstance;
    }

    public void load(){
        fakeData();
    }

    public ArrayList<Topic> getTopicsList() {
        return mTopicsList;
    }

    public ArrayList<Vocabulary> getVocabularyList(Topic topic) {
        ArrayList<Vocabulary> list = new ArrayList<>();
        for(Vocabulary v : mVocabularyList){
            if(v.getTopicId() == topic.getId()){
                list.add(v);
            }
        }
        return list;
    }

    private void fakeData(){
        Topic t1 = new Topic(1, "T1");
        Topic t2 = new Topic(2, "T2");
        Topic t3 = new Topic(3, "T3");
        Topic t4 = new Topic(4, "T4");

        mTopicsList.add(t1);
        mTopicsList.add(t2);
        mTopicsList.add(t3);
        mTopicsList.add(t4);

        Vocabulary v1 = new Vocabulary("W11", "P11", "M11", 1);
        Vocabulary v2 = new Vocabulary("W12", "P12", "M12", 1);
        Vocabulary v3 = new Vocabulary("W13", "P13", "M13", 1);
        Vocabulary v4 = new Vocabulary("W14", "P14", "M14", 1);

        mVocabularyList.add(v1);
        mVocabularyList.add(v2);
        mVocabularyList.add(v3);
        mVocabularyList.add(v4);

        mVocabularyList.add(new Vocabulary("W21", "P21", "M21", 2));
        mVocabularyList.add(new Vocabulary("W22", "P22", "M22", 2));
        mVocabularyList.add(new Vocabulary("W23", "P23", "M23", 2));
        mVocabularyList.add(new Vocabulary("W24", "P24", "M24", 2));

    }
}
