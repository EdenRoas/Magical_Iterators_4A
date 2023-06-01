#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#pragma once
using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> container;

    public:
        MagicalContainer();                        // defult constractor
        MagicalContainer(MagicalContainer &other); // copy constractor
        ~MagicalContainer();                       // destructor

        void addElement(int num);
        void removeElement(int num);
        size_t size() const;
    
    // This Class return the numbers in ascending order
        class AscendingIterator //: public iterator
        {
        private:
            const MagicalContainer &container;
            size_t index;

        public:
            AscendingIterator(const MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            int operator*() const;
            AscendingIterator begin() const;
            AscendingIterator end() const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator++();
        };
        class SideCrossIterator
        {
        private:
            const MagicalContainer &container;
            size_t forwardIndex;
            size_t backwardIndex;

        public:
            SideCrossIterator(const MagicalContainer &container,size_t forward = 0,size_t backward = 0);
            SideCrossIterator(const SideCrossIterator &other);
            int operator*() const;
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator++();
        };
        class PrimeIterator
        {
        private:
            const MagicalContainer &container;
            size_t index;

            bool isPrime(int number);

        public:
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            int operator*() const;
            PrimeIterator begin() const;
            PrimeIterator end() const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            PrimeIterator &operator=(const PrimeIterator &other);
            PrimeIterator &operator++();
            
        };
    };

}