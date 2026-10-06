#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class ISubscriber{
    public:
        virtual void update() = 0;
};

class IChannel{
    public:
        virtual void subscribe(ISubscriber*) = 0;
        virtual void unsubscribe(ISubscriber*) = 0;
        virtual void notify() = 0;
};

class Channel : public IChannel{
    private:
        std::vector<ISubscriber*> subscriberList;
        std::string name;
        std::string latestVideo;
    public:
        Channel(std::string name):name(name){}
        void subscribe(ISubscriber* subscriber) override{
            if(std::find(subscriberList.begin(),subscriberList.end(),subscriber)==subscriberList.end()){
                subscriberList.push_back(subscriber);
            };
        }
        void unsubscribe(ISubscriber* subscriber) override{
            auto idx = std::find(subscriberList.begin(),subscriberList.end(),subscriber);
            if(idx != subscriberList.end())
                subscriberList.erase(idx);
        }
        void notify(){
            for(ISubscriber* sub:subscriberList)
                sub->update();
        }
        void uploadVideo(std::string videoName){
            latestVideo = videoName;
            std::cout<<"latest video from channel "<<name<<" is: "<<videoName<<"\n";
            notify();
        }
        std::string getLatestVideo(){
            return name+" : "+latestVideo;
        }
};

class subscriber:public ISubscriber{
    private:
        //concrete obeject so that we can access the other function than obeserver pattern like getting video details
        Channel* channel;
        std::string name;
    public:
        subscriber(Channel* channel,std::string name):channel(channel),name(name){}

        void update() override {
            std::cout<<"hey, got this new video for "<<name<<" from "<<channel->getLatestVideo()<<std::endl;
        }
};

int main(){
    Channel* ch1 = new Channel("hehe");

    subscriber* sub1 = new subscriber(ch1,"abhi");
    subscriber* sub2 = new subscriber(ch1,"bhibhi");

    ch1->subscribe(sub1);
    ch1->subscribe(sub2);

    ch1->uploadVideo("intresting video");

    ch1->unsubscribe(sub1);

    ch1->uploadVideo("new intresting video");

    return 0;
}