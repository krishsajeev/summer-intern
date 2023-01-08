import Foundation
protocol Connection {
    var amount: Float {get set}
    func setAmount(amount: Float)
}

class Landline: Connection {
    public var STDCode: String
    public var number: String
    public var amount: Float
    
    init (number: String, STDCode: String) {
        amount = 0.0
        self.STDCode = STDCode
        self.number = number
    }
    func setAmount(amount: Float) {
        self.amount = amount
    }
}

class Mobile: Connection {
    public var number: String
    public var amount: Float
    
    init (number: String) {
        amount = 0.0
        self.number = number
    }
    func setAmount(amount: Float) {
        self.amount = amount
    }
}

class BillPayment<T> {
    public var records = [String : T] ()
    
    public func addConnection(connection: T, number: String) {
        records[number] = connection
    }
    
    public func addConnection(connection: T, STDCode: String, number: String) {
        records[STDCode + number] = connection
    }
    
    public func payBill(number:String) {
        if let obj = records[number] as? Connection{
            obj.setAmount(amount: 0)
            print("BILL PAID FOR CONNECTION NUMBER", number)
        }
    }
    
    public func updateBill(number: String, amount: Float) {
        if let obj = records[number] as? Connection{
            obj.setAmount(amount: amount)
            print("BILL GENERATED FOR CONNECTION NUMBER", number)
        }
    }
    
    public func displayConnections() {
        for num in records.keys {
            let val = records[num] as? Connection
            print(num, " --- ", val!.amount)
        }
    }
}

var mobilePayment = BillPayment<Mobile> ()
var LandlinePayment = BillPayment<Landline> ()


while(true) {
    print("ENTER YOUR MODE \n 1 --- MOBILE \n 2 --- LANDLINE \n")
    let mode = readLine()
    
    print("ENTER YOUR OPTION\n 1 --- CREATE CONNECTION\n 2 --- PAY BILL\n 3 --- UPDATE BILL\n\n")
    let option = readLine()
    
    print("ENTER THE NUMBER\n")
    let number = readLine()
    
    if mode == "1" {
        switch(option){
        case "1":
            mobilePayment.addConnection(connection: Mobile(number: number!), number: number!)
            break
        case "2":
            mobilePayment.payBill(number: number!)
            break
        case "3":
            print("ENTER THE AMOUNT\n")
            let amount = Float(readLine()!)!
            mobilePayment.updateBill(number: number!, amount: amount)
        default:
            mobilePayment.displayConnections()
        }
    }
    else {
        print("ENTER THE STD CODE\n")
        let code = readLine()
        
        switch(option){
        case "1":
            LandlinePayment.addConnection(connection: Landline(number: number!, STDCode: code!), number: number!)
            break
        case "2":
            LandlinePayment.payBill(number: number!)
            break
        case "3":
            print("ENTER THE AMOUNT\n")
            let amount = Float(readLine()!)!
            LandlinePayment.updateBill(number: number!, amount: amount)
        default:
            LandlinePayment.displayConnections()
        }
    }
}
