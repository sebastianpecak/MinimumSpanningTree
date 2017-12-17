.PHONY: clean All

All:
	@echo "----------Building project:[ MSP_SebastianPecak - Debug ]----------"
	@"$(MAKE)" -f  "MSP_SebastianPecak.mk"
clean:
	@echo "----------Cleaning project:[ MSP_SebastianPecak - Debug ]----------"
	@"$(MAKE)" -f  "MSP_SebastianPecak.mk" clean
