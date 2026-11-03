/*
===============================================================================
 TESTBENCH CHECKLIST:

    [ ] Write known K/V vectors to the same address.
    [ ] Read them back and compare against expected values.
    [ ] Verify K and V are accessed simultaneously.
    [ ] Verify read-after-write behavior.
    [ ] Write different values to multiple addresses.
    [ ] Read multiple addresses back-to-back.
    [ ] Hold rsp_ready LOW and verify rsp_valid/data remain stable.
    [ ] Verify no request is accepted while the response is stalled.
    [ ] Verify reset clears control state.
    [ ] Verify no read response is generated for a write.
    [ ] Verify no data is lost during request/response handshakes.

===============================================================================
*/