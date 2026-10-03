#include<iostream>
#include<fstream>
#include<vector>
#include<string>


class documentEditor{
    private:
        std::vector<std::string> elements;
        std::string renderedDocment;
    public:
        void addText(std::string text){
            elements.push_back(text);
        }
        void addImage(std::string path){
            elements.push_back(path);
        }
        void render(){
            if(renderedDocment.empty()){
                for(std::string &s:elements){
                    if(s.ends_with(".jpg"))
                        renderedDocment = renderedDocment + "[image] " + s +"\n";
                    else
                        renderedDocment = renderedDocment + s + "\n";
                }
            }
        }
        void save(){
            std::ofstream file("document.txt");
            file << renderedDocment;
            file.close();
        }
};

int main(){
    documentEditor doce;
    //single class doing everything
    doce.addText("hello");
    doce.addImage("hello.jpg");
    doce.render();
    doce.save();

    return 0;
}