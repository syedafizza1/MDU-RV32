import chisel3._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation


class MultiplierTest extends FreeSpec with ChiselScalatestTester {

  "Multiplier Gate Test" in {
    test(new Multiplier()){ c =>
      c.io.src_a.poke(4294967295L.U)
      c.io.src_b.poke(100.U)
      c.io.valid.poke(1.B)
      c.io.op.poke(7.U)
      c.clock.step(1)
      c.io.valid.poke(0.B)

      c.clock.step(100)
      c.io.output.bits.expect("h5f".U)
    }
  }
}




