import random


class Gerador:
    cpf = []
    v1 = 0
    v2 = 0

    @staticmethod
    def generate(self):
        for i in range(1, 10):
            self.cpf.append(int(random.random()*9))
        self.cpf.reverse()
        for i in range(9):
            self.v1 += int(self.cpf[i])*(9 - (i % 10))
            self.v2 += int(self.cpf[i])*(9 - ((i + 1) % 10))

        self.v1 = (self.v1 % 11) % 10
        self.v2 += self.v1*9
        self.v2 = (self.v2 % 11) % 10

        self.cpf.reverse()

        self.cpf.append(self.v1)
        self.cpf.append(self.v2)
        return "".join(map(str, self.cpf))


if __name__ == "__main__":
    print(Gerador.generate(Gerador()))
