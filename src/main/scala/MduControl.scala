import chisel3._
import chisel3.util._
import chisel3.experimental._

class MduControl extends Module {
  val io = IO(new Bundle {
    val aluOp: UInt = Input(UInt(2.W))
    val f7: UInt = Input(UInt(7.W))
    val f3: UInt = Input(UInt(3.W))
    val aluSrc: Bool = Input(Bool())
    val op: UInt = Output(UInt(4.W))
  })

  when(io.f7 === 1.U && (io.f3 === 0.U || io.f3 === 1.U || io.f3 === 2.U || io.f3 === 3.U || io.f3 === 4.U || io.f3 === 5.U || io.f3 === 6.U || io.f3 === 7.U)){
      io.op := io.f3
  }
  .otherwise{
      io.op := io.aluOp
  }
}