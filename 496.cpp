/*
496. Toy Factory

Factory is a design pattern in common usage. Please implement a ToyFactory which can generate proper toy based on the given type.

Have you met this question in a real interview? Yes
Example
ToyFactory tf = ToyFactory();
Toy toy = tf.getToy('Dog');
toy.talk(); 
>> Wow

toy = tf.getToy('Cat');
toy.talk();
>> Meow
*/

/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    void talk() const {
        cout << "Wow" << endl;
    }
};

class Cat: public Toy {
    void talk() const {
        cout << "Meow" << endl;
    }
};

class ToyFactory {
private:
    const string kCat = "Cat";
    const string kDog = "Dog";
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        if (type == kCat) {
            return new Cat();
        } else if (type == kDog) {
            return new Dog();
        }
        return NULL;
    }
};
