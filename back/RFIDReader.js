const Modbus = require('jsmodbus')
const net = require('net')

class RFIDReader {
  constructor(host, port = 502) {
    this.host = host
    this.port = port
    this.socket = new net.Socket()
    this.client = new Modbus.client.TCP(this.socket, 1)
    this.connection = null
  }

  connect() {
    return new Promise((resolve, reject) => {
      this.socket.connect({ host: this.host, port: this.port }, () => {
        console.log(`Connexion au lecteur RFID établie à ${this.host}:${this.port}`)
        resolve()
      })

      this.socket.on('error', (err) => {
        console.error('Erreur lors de la connexion:', err)
        reject(err)
      })
    })
  }

  disconnect() {
    this.socket.end()
    console.log('Déconnecté du lecteur RFID')
  }

async readRFIDTag(register = 0, length = 15) {
  try {
  const resp = await this.client.readHoldingRegisters(register, length)
  const buffer = Buffer.from(resp.response._body._valuesAsBuffer)
  const trimmed = buffer.filter(b => b !== 0x00)
  if (trimmed.length === 0) return null

  // Vérifier si c'est la valeur par défaut (54 78 02 01)
  const defaultHex = '54 78 02 01'
  const hexText = Buffer.from(trimmed).toString('hex').toUpperCase().match(/.{1,2}/g).join(' ')
  if (hexText === defaultHex) {
    return null
  }

  const text = Buffer.from(trimmed).toString('utf8')
  if (/^[\x20-\x7E]+$/.test(text)) {
    return text
  }

  return hexText
  } catch (err) {
  console.error('Erreur lors de la lecture du tag:', err)
  throw err
  }
}

  async writeCommand(register, values) {
    try {
      const buffer = Buffer.from(values, 'utf8')
      const data = []
      for (let i = 0; i < buffer.length; i += 2) {
        data.push(buffer.readUInt16BE(i))
      }
      await this.client.writeMultipleRegisters(register, data)
    } catch (err) {
      console.error("Erreur lors de l'écriture de la commande:", err)
      throw err
    }
  }
}

module.exports = RFIDReader
