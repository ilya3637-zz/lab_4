#include <iostream>
#include <list>


using namespace std;



/** \class Node - êëàññ îïèñàíèÿ è ìåòîäîâ ïîëÿ
 */
class Node{
    list<Node> nodes; /**< ñïèñîê äî÷åðíèõ ïîëåé */
    int serialNum; /**< ñîäåðæèìîå ïîëÿ */
 public:
     /** \brief Êîíñòðóêòîð áåç ïàðàìåòðîâ
      */

     Node();
     /** \brief Êîíñòðóêòîð ñ çàäàíèåì ñîäåðæèìîãî ïîëÿ
      *
      * \param [in] serial - ñîäåðæèìîå äëÿ íîäû
      *
      */

     Node(int);
     /** \brief Ìåòîä äîáàâëåíèÿ äî÷åðíèõ ïîëåé
      *
      * \param [in] node - ññûëêà íà îáúåêò íîâîé íîäû
      *
      */

     void add(const Node&);
     /** \brief Ìåòîä ïîèñêà ïî äåðåâó
      *
      * \param [in] serial - ñîäåðæèìîå íîäû äëÿ ïîèñêà
      * \return ññûëêó íà íîäó
      *
      */

     Node& search(int);
     /** \brief Ìåòîä ïîëó÷åíèÿ ñîäåðæèìîãî íîäû
      *
      * \return çíà÷åíèå íîäû
      *
      */

     int  getSerial();
     /** \brief Ìåòîä ðàñïå÷àòûâàåò ñïèñîê â îáðàòíîì ïîðÿäêå
      *
      */

     void printForward();
     /** \brief Ìåòîä ðàñïå÷àòûâàåò ñïèñîê â ïðÿìîì ïîðÿäêå
      *
      */

     void printBack();
     /** \brief Ìåòîä ðàñïå÷àòûâàåò ñïèñîê â ñèììåòðè÷íîì ïîðÿäêå
      *
      */

     void printSymetric();
};
Node * node; /**< ãëîáàëüíàÿ ïåðåìåííàÿ äëÿ óêàçàòåëÿ íà èñêîìûé ýëåìåíòû ñïèñêà */
Node::Node(){
    count = 0;
}
void Node::printForward(){

    if(serialNum != 0){
    cout<<serialNum<<" ";
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printForward();
    }

}
void Node::printBack(){

    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printBack();
    }
    if(serialNum != 0){
    cout<<serialNum<<" ";
    }
}

void Node::printSymetric(){
    bool flag = true;
    if(nodes.size() == 0){
        if(serialNum != 0){
            cout<<serialNum<<" ";
        }
    }
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it).printSymetric();
        if(flag){
            if(serialNum != 0){
                cout<<serialNum<<" ";
            }
            flag = false;
        }
    }
}
Node::Node(int serial){
    serialNum = serial;
}
int Node::getSerial() {
    return serialNum;
}

Node& Node::search(int num){
    for(std::list<Node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        if((*it).getSerial() == num){
            node = &(*it);
        } else {
            (*it).search(num);
        }
    }
    return (*node);
}

void Node::add(const Node& node){
    nodes.push_back(node);
}

/** \brief Ìåòîä main îñíîâíîé ìåòîä ïðîãðàììû
 *
 * \return êîä îøèáêè
 *
 */

int main()
{
    /** \brief Çàïîëíåíèå ñïèñêà è ðàñïå÷àòêà
     */

    int serialCounter = 0;
    Node * baseNode = new Node(serialCounter);
    int countOfNodes = 0;
    int nextSerial = 0;
    cin>>countOfNodes;

    for(int i = 0;i < countOfNodes; i ++){
        cin>>nextSerial;
        if(nextSerial ==  0){
            ++serialCounter;
            baseNode->add(*(new Node(serialCounter)));
        } else {
            ++serialCounter;
            baseNode->search(nextSerial).add(*(new Node(serialCounter)));
        }

    }
    baseNode->printForward();
    cout<<"\n";
    baseNode->printBack();
    cout<<"\n";
    baseNode->printSymetric();



    return 0;
}
