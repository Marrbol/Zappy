/*
** EPITECH PROJECT, 2023
** bootstrap plazza
** File description:
** IProcess
*/

#ifndef IPROCESS_HPP_
#define IPROCESS_HPP_

class IProcess {
    public:
        IProcess() = default;
        ~IProcess() = default;
        virtual int forkProcess() = 0;
        virtual void exitProcess(int status) = 0;
        virtual void waitProcess() = 0;

    protected:
    private:
};

#endif /* !IPROCESS_HPP_ */
