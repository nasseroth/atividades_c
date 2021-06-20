package app.enums;

public enum TipoAnimalEnum {

	CAO(1, "C�O"), GATO(2, "GATO"), PASSARO(3, "P�SSARO");

	private Integer cod;
	private String descricao;

	private TipoAnimalEnum(Integer cod, String descricao) {
		this.cod = cod;
		this.descricao = descricao;
	}

	public static TipoAnimalEnum toEnum(Integer cod) {
		if (cod == null) {
			return null;
		}

		for (TipoAnimalEnum tipoAnimal : TipoAnimalEnum.values()) {
			if (cod.equals(tipoAnimal.getCod())) {
				return tipoAnimal;
			}
		}

		throw new IllegalArgumentException("ID do tipo de animal inv�lido: " + cod);
	}

	public Integer getCod() {
		return cod;
	}

	public void setCod(Integer cod) {
		this.cod = cod;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
}
