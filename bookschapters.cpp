#include <iostream>
#include <vector>

class Node {
public:
    std::string name;
    std::vector<Node*> children;

    Node(const std::string& nodeName) : name(nodeName) {}

    void addChild(Node* child) {
        children.push_back(child);
    }

    void printNodes() {
        std::cout << name << std::endl;
        for (Node* child : children) {
            child->printNodes();
        }
    }
};

int main() {
    // Construct the tree
    Node* book = new Node("Book");
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    Node* section2_1 = new Node("Section 2.1");
    Node* section2_2 = new Node("Section 2.2");
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    Node* subsection1_1_2 = new Node("Subsection 1.1.2");
    Node* subsection1_2_1 = new Node("Subsection 1.2.1");
    Node* subsection1_2_2 = new Node("Subsection 1.2.2");
    Node* subsection2_1_1 = new Node("Subsection 2.1.1");
    Node* subsection2_1_2 = new Node("Subsection 2.1.2");
    Node* subsection2_2_1 = new Node("Subsection 2.2.1");
    Node* subsection2_2_2 = new Node("Subsection 2.2.2");

    book->addChild(chapter1);
    book->addChild(chapter2);
    chapter1->addChild(section1_1);
    chapter1->addChild(section1_2);
    chapter2->addChild(section2_1);
    chapter2->addChild(section2_2);
    section1_1->addChild(subsection1_1_1);
    section1_1->addChild(subsection1_1_2);
    section1_2->addChild(subsection1_2_1);
    section1_2->addChild(subsection1_2_2);
    section2_1->addChild(subsection2_1_1);
    section2_1->addChild(subsection2_1_2);
    section2_2->addChild(subsection2_2_1);
    section2_2->addChild(subsection2_2_2);

    // Print the nodes
    book->printNodes();

    // Clean up the dynamically allocated nodes
    delete book;
    delete chapter1;
    delete chapter2;
    delete section1_1;
    delete section1_2;
    delete section2_1;
    delete section2_2;
    delete subsection1_1_1;
    delete subsection1_1_2;
    delete subsection1_2_1;
    delete subsection1_2_2;
    delete subsection2_1_1;
    delete subsection2_1_2;
    delete subsection2_2_1;
    delete subsection2_2_2;

    return 0;
}
