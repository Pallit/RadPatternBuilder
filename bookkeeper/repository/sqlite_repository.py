import sqlite3

from itertools import count
from typing import Any

from bookkeeper.repository.abstract_repository import AbstractRepository, T


class SqliteRepository(AbstractRepository[T]):
    def __init__(self) -> None:
        self._counter = count(1)

    def add(self, obj: T) -> int:
        return 0

    def get(self, pk: int) -> T | None:
        return

    def get_all(self, where: dict[str, Any] | None = None) -> list[T]:
        return None

    def delete(self, pk: int) -> None:
        return
