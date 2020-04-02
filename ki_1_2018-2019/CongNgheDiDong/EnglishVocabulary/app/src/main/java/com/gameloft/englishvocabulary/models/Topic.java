package com.gameloft.englishvocabulary.models;

public class Topic {
    private int id;
    private String name;

    public Topic(int _id, String _name){
        id = _id;
        name = _name;
    }

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    @Override
    public String toString() {
        return id + " " + name;
    }
}
