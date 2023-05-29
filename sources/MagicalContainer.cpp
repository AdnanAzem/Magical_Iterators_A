#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

namespace ariel{

    // Helper function to check if a number is prime
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i <= std::sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    //=========================== MagicalContainer Class ===========================

    MagicalContainer::MagicalContainer() {
    }

    // Method to add an element to the container
    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
        std::sort(elements.begin(), elements.end());
    }

    // Method to remove an element from the container
    void MagicalContainer::removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                break;
            }
        }
    }

    // Method to retrieve the size of the container
    int MagicalContainer::size() const {
        return elements.size();
    }

    vector<int> MagicalContainer::getElements() const{
        return elements;
    }


    //=========================== AscendingIterator Class ===========================

    MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer &cont, int curr)
        : container(cont), currentIndex(curr) {}

    // Default constructor
    MagicalContainer::AscendingIterator::AscendingIterator( MagicalContainer& magicalContainer) : container(magicalContainer), currentIndex(0) {}

    // Copy constructor
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), currentIndex(other.currentIndex) {}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Assignment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (this != &other) {
            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    // Equality comparison
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &container == &other.container && currentIndex == other.currentIndex;
    }

    // Inequality comparison
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    // Greater than comparison
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return currentIndex > other.currentIndex;
    }

    // Less than comparison
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return currentIndex < other.currentIndex;
    }

    // Dereference operator
    int MagicalContainer::AscendingIterator::operator*() const {
        return container.getElements().at((std::vector<int>::size_type)currentIndex);
        
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        currentIndex++;
        return *this;
    }

    // Method to get an AscendingIterator pointing to the first element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(container,0);
        
    }

    // Method to get an AscendingIterator pointing one position past the last element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(container,container.size());
    }
    //=========================== End AscendingIterator Class ===========================


    //=========================== SideCrossIterator Class ===========================

    MagicalContainer::SideCrossIterator::SideCrossIterator( MagicalContainer &cont, int curr, bool flag)
        : container(cont), currentIndex(curr), fromStart(flag) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator( MagicalContainer& magicalContainer) 
        : container(magicalContainer), currentIndex(0), fromStart(true) {}

    // Copy constructor
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) 
        : container(other.container), currentIndex(other.currentIndex), fromStart(other.fromStart) {}

    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Assignment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if (this != &other) {
            container = other.container;
            currentIndex = other.currentIndex;
            fromStart = other.fromStart;
        }
        return *this;
    }

    // Equality comparison
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return currentIndex == other.currentIndex && fromStart == other.fromStart;
    }

    // Inequality comparison
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    // Greater than comparison
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return currentIndex > other.currentIndex;
    }

    // Less than comparison
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return currentIndex < other.currentIndex;
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const {
        if (fromStart)
            return container.elements[(std::vector<int>::size_type)currentIndex];
        else
            // return container.elements[(std::vector<int>::size_type)endIndex];
            return container.elements[(std::vector<int>::size_type)(container.size() - currentIndex )];
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (fromStart){
            if(currentIndex != container.size()/2)
            ++currentIndex;
            else
                currentIndex = container.size();
            // fromStart = false;
        }
        // else if(!fromStart){
        //     // --endIndex;
        //     ++currentIndex;
        //     // fromStart = true;
        // }
        fromStart = !fromStart;

        return *this;
    }

    // Method to get a SideCrossIterator pointing to the first element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(container,0,true);
    }

    // Method to get a SideCrossIterator pointing one position past the last element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(container,container.size(),false);
    }

    //=========================== SideCrossIterator Class ===========================


    //=========================== PrimeIterator Class ===========================

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &cont, int curr)
        : container(cont), currentIndex(curr) {}

    // Default constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& magicalContainer) : container(magicalContainer), currentIndex(0) {
        // Skip non-prime numbers at the beginning
        while (currentIndex < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)currentIndex))) {
            currentIndex++;
        }
    }

    // Copy constructor
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(other.container), currentIndex(other.currentIndex) {}

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Assignment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if (this != &other) {
            // container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    // Equality comparison
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &container == &other.container && currentIndex == other.currentIndex;
    }

    // Inequality comparison
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    // Greater than comparison
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return currentIndex > other.currentIndex;
    }

    // Less than comparison
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return currentIndex < other.currentIndex;
    }

    // Dereference operator
    int MagicalContainer::PrimeIterator::operator*() const {
        return container.getElements().at((std::vector<int>::size_type)currentIndex);
    }

    // Pre-increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        currentIndex++;
        while (currentIndex < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)currentIndex))) {
            currentIndex++;
        }
        return *this;
    }

        // Method to get a PrimeIterator pointing to the first prime element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        // return PrimeIterator(*this);
        return PrimeIterator(container,0);
    }

    // Method to get a PrimeIterator pointing one position past the last prime element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        return PrimeIterator(container,container.size());
    }

    //=========================== PrimeIterator Class ===========================

    //=========================== MagicalContainer Class ===========================
}






    